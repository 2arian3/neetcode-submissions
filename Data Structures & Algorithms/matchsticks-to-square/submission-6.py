class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        area = sum(matchsticks)

        if area % 4 != 0:
            return False

        each_side = area // 4
        sides = [0 for _ in range(4)]
        matchsticks = sorted(matchsticks, reverse=True)

        def _backtrack(index: int):
            if index == len(matchsticks):
                return True

            for side in range(4):
                stick = matchsticks[index]
                if sides[side] + stick <= each_side:
                    sides[side] += stick
                    if _backtrack(index + 1):
                        return True
                    sides[side] -= stick

                if sides[side] == 0:
                    break

            return False

        return _backtrack(0)