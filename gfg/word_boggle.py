class TrieNode:
    def __init__(self):
        self.word_end_count = 0
        self.char_map = {}

    def insert(self, s):
        curr = self
        new_chars = 0
        for ch in s:
            if ch in curr.char_map:
                curr = curr.char_map[ch]
            else:
                curr.char_map[ch] = TrieNode()
                curr = curr.char_map[ch]
                new_chars += 1
        # if not new_chars and curr.word_end_count>0:
        #     raise Exception("word already in trie.")
        curr.word_end_count += 1


def get_all_words_from_boggle(trie, boggle, n, m, i, j, visited, selected, s, ans_words):
    if boggle[i][j] not in trie.char_map:
        return
    s += boggle[i][j]
    if trie.char_map[boggle[i][j]].word_end_count > 0:
        for k in visited.keys():
            selected[k] = True
        ans_words.add(s)
    visited[i * m + j] = True
    adjacent = [(1, -1), (-1, 1), (1, 1), (-1, -1),
                (0, 1), (1, 0), (0, -1), (-1, 0)]
    for cord in adjacent:
        new_i, new_j = i + cord[0], j + cord[1]
        if new_i >= n or new_i < 0 or new_j >= m or new_j < 0 or (new_i * m + new_j) in visited or (
                new_i * m + new_j) in selected:
            continue
        get_all_words_from_boggle(trie.char_map[boggle[i][j]], boggle, n, m, new_i, new_j, visited, selected, s,
                                  ans_words)
    visited[i * m + j] = False


tc = int(input())
while tc:
    trie = TrieNode()
    no_of_words = int(input())
    words = list(map(str, input().split()))
    for word in words:
        trie.insert(word)
    n, m = list(map(int, input().split()))
    arr = list(map(str, input().split()))
    boggle = []
    ans_words = set()
    for i in range(n):
        boggle.append(arr[(i * m):((i + 1) * m)])
    selected = {}
    for i in range(n):
        for j in range(m):
            if (i * m + j) in selected:
                continue
            get_all_words_from_boggle(
                trie, boggle, n, m, i, j, {}, selected, '', ans_words)
    if len(ans_words) == 0:
        print(-1)
    else:
        ans = list(ans_words)
        ans.sort()
        print(*ans)
    tc -= 1
