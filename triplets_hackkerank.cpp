/*inp: 6 3
1 3 9 9 27 81
 out: 6
 */


long countTriplets(vector<long> arr, long r) {
    unordered_map<long,long>mp1,mp2;
    long count;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        count+=mp2[arr[i]];
        mp2[arr[i]*r]+=mp1[arr[i]];
        mp1[arr[i]*r]++;
    }
    return count;

}