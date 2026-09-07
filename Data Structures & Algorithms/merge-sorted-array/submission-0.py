class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end1: int = m - 1
        end2: int = n - 1

        arrend: int = len(nums1) - 1

        while arrend >= 0:
            if end1 >= 0 and end2 >= 0:
                if nums1[end1] > nums2[end2]:
                    nums1[arrend] = nums1[end1]
                    end1 -= 1
                else:
                    nums1[arrend] = nums2[end2]
                    end2 -= 1
            elif end1 >= 0:
                nums1[arrend] = nums1[end1]
                end1 -= 1
            elif end2 >= 0:
                nums1[arrend] = nums2[end2]
                end2 -= 1

            arrend -= 1
