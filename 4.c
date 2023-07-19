int* newNums = NULL;
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    newNums = realloc(newNums, (nums1Size+nums2Size)*sizeof(int));
    int currNum1 = 0;
    int currNum2 = 0;
    for(int i=0; i < nums1Size+nums2Size; i++)
	{
        int nextNum = 0;
        if(currNum1 >= nums1Size)
        {
            //printf("A HERE\n");
            newNums[i] = nums2[currNum2];
            currNum2++;
            //printf("A END\n");
        }
        else if(currNum2 >= nums2Size)
        {
            //printf("B HERE\n");
            newNums[i] = nums1[currNum1];
            currNum1++;
        }
        else
            {
                //printf("C HERE\n");
            if(nums1[currNum1] < nums2[currNum2])
            {
                nextNum = nums1[currNum1];
                currNum1++;
            }
            else
            {
                nextNum = nums2[currNum2];
                currNum2++;
            }
            newNums[i] = nextNum;
            //printf("D HERE\n");
            }
	}
    if((nums1Size + nums2Size) % 2 == 0)
    {
        ////printf("E HERE\n");
        int a = ((nums1Size + nums2Size)/2)-1;
        ////printf("%d %d %d %lf", a, newNums[a], newNums[a+1], ((newNums[a] + newNums[a+1])/2.0));
        return (newNums[a] + newNums[a+1])/2.0;
    }
    else
    {
        //printf("F HERE\n");
        return newNums[(int)ceil((nums1Size + nums2Size)/2)];
    }
    return -1;
}
