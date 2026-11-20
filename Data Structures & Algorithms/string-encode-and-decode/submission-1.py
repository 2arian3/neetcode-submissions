class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_string = ''

        for s in strs:
            encoded_string += f'{str(len(s))}#{s}'

        return encoded_string

    def decode(self, s: str) -> List[str]:
        decoded_strings = []

        i = 0

        while i < len(s):
            count = ''
            while s[i] != '#':
                count += s[i]
                i += 1

            i += 1
            count = int(count)
            decoded_strings.append(s[i : i + count])
            i += count

        return decoded_strings