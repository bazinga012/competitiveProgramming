from collections import deque
# https://leetcode.com/problems/design-browser-history/
class BrowserHistory:
    
    def __init__(self, homepage: str):
        self.dq = deque()
        self.dq.append(homepage)
        self.curr_idx = 0
        self.end_idx = 0
    
    def visit(self, url: str) -> None:
        if self.dq[self.curr_idx] == url:
            return
        self.end_idx= self.curr_idx + 1
        self.curr_idx = self.end_idx
        if (self.curr_idx) == len(self.dq):
            self.dq.append(url)
        else:
            self.dq[self.end_idx] = url
        

    def back(self, steps: int) -> str:
        self.curr_idx = max(self.curr_idx - steps, 0)
        return self.dq[self.curr_idx]
        

    def forward(self, steps: int) -> str:
        self.curr_idx = min(self.curr_idx + steps, self.end_idx)
        return self.dq[self.curr_idx]
    
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)