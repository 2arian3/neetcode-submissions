class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        s1, s2 = {'0000'}, {target}

        steps = 0
        visited = set(deadends)

        if target == '0000':
            return steps

        if '0000' in visited:
            return -1

        while s1 and s2:
            if len(s2) < len(s1):
                s1, s2 = s2, s1

            steps += 1
            temp = set()

            for comb in s1:
                for i in range(4):
                    for j in {-1, 1}:
                        digit = str((int(comb[i]) + j + 10) % 10)
                        nxt = comb[:i] + digit + comb[i+1:]

                        if nxt in s2:
                            return steps

                        if nxt in visited:
                            continue

                        visited.add(nxt)
                        temp.add(nxt)
            s1 = temp

        return -1