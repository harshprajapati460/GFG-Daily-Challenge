# def arrayOperations(self, n : int, arr : List[int]) -> int:
#         zero = 0
#         for i in range(len(arr)):
#             if arr[i] == 0:
#                 zero+=1
#         if zero == 0:
#             return -1
#         count = 0
#         ans = 0
#         for i in range(len(arr)):
#             if arr[i] != 0:
#                 count+=1
#             else :
#                 if count > 0:
#                     ans+=1
#                 count = 0
#         if count > 0:
#             ans+=1
#         return ans 