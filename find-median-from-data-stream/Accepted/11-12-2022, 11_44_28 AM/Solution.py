// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder:

    def __init__(self):
        self.lis=[]

    def addNum(self, num: int) -> None:
        ind=self.binary_search(num)
        self.lis.insert(ind,num)
        

    def findMedian(self) -> float:
        if len(self.lis)%2==0:
            mid=len(self.lis)//2
            return (self.lis[mid]+self.lis[mid-1])/2
        else:
            mid=len(self.lis)//2
            return self.lis[mid]
    def binary_search(self,num):
        if len(self.lis)==0:
            return 0
        start=0
        end=len(self.lis)-1
        while(start<=end):
            mid=(start+end)//2
            if self.lis[mid]==num:
                return mid
            elif self.lis[mid]<num:
                start=mid+1
            else:
                end=mid-1
        return start