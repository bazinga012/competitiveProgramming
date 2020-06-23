# https://leetcode.com/problems/text-justification/
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
            output = []
            i = 0
            max_width = maxWidth
            while True:
                if i == len(words): break
                cws = []
                wtl = 0
                while i < len(words):
                    word = words[i]
                    if len(word) > max_width: return -1
                    if (wtl + len(word) + len(cws)) > max_width:
                        break
                    cws.append(word)
                    wtl += (len(word))
                    i += 1
                if len(cws) == 1:
                    output.append(cws[0] + " " * (max_width - wtl))
                    continue
                if i == len(words):
                    output.append(" ".join(cws).ljust(max_width, " "))
                    break
                min_occ_space = (wtl + len(cws) - 1)
                space_left = max_width - min_occ_space

                extra_space_per_word = int(space_left / (len(cws) - 1))
                remaining_space = space_left % (len(cws) - 1)
                prefix = ""
                space = " " * (1 + extra_space_per_word)
                suffix = cws.pop(-1)
                for w in cws:
                    v = (w + space)
                    if remaining_space:
                        v += " "
                        remaining_space -= 1
                    prefix += v
                output.append(prefix + suffix)
            return output