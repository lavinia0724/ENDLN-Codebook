int binary_search(int arr[maxn], int lef, int rig, int target){
    if(lef > rig) return 0x3f3f3f3f;
    int mid = (lef + rig) >> 1;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target){
        return binary_search(arr, lef, mid - 1, target);
    }
    else{
        return binary_search(arr, mid + 1, rig, target);
    }
}