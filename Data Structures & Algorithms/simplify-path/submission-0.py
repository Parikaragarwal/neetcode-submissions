class Solution:
    def simplifyPath(self, path: str) -> str:
        s: str = ""
        path = path+"/"
        record: List[str] = []
        chars: List[str] = []
        for ch in path:
            if ch != "/":
                chars.append(ch)
            else:
                s: str = "".join(chars)
                if s == "..":
                    if record:
                        record.pop()
                elif s != "." and s != "":
                    record.append(s)

                chars = []
        return "/"+"/".join(record)