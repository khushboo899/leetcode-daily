class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
        }
        PriorityQueue<Integer>pq=new PriorityQueue<>((a,b)->map.get(b)-map.get(a));
        for(int key:map.keySet()){
            pq.add(key);
        }
        int[]ans=new int[k];
        int idx=0;
        for(int i=0;i<k;i++){
            ans[idx++]=pq.remove();
        }
        return ans;
    }
}