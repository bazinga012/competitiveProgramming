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
                new_chars+=1
        if not new_chars:
            raise Exception("word already in trie.")
        curr.word_end_count += 1

    def search(self, s):
        curr = self
        for ch in s:
            if ch in curr.char_map:
                curr = curr.char_map[ch]
            else:
                return False
        return curr.word_end_count > 0

    def remove(self, s, n, i=0):
        if n <= i:
            return
        curr = self
        ch = s[i]
        if ch in curr.char_map:
            curr = curr.char_map[ch]
            if i == n-1:
                if curr.word_end_count == 0:
                    raise Exception("Given string not part of trie.")
                curr.word_end_count -= 1
            else:
                removed_char = curr.remove(s, n, i+1)
                if removed_char:
                    del curr.char_map[removed_char]
            if not curr.char_map.keys():
                del curr
                return ch
        else:
            raise Exception("Given string not part of trie.")

    def print_dict(self, s=''):
        curr = self
        if curr.word_end_count > 0:
            print(s)
        chars = list(curr.char_map.keys())
        chars.sort()
        for ch in chars:
            curr.char_map[ch].print_dict(s + ch)