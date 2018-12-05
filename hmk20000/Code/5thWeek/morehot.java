import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i=0; i<scoville.length; i++){
            pq.add(scoville[i]);
        }
        int answer=0;
        while(pq.size()>1){
            pq.add(pq.poll()+pq.poll()*2);
            answer++;
            if(check(pq,K)){
                break;
            }
        }
        if(pq.size()==1){
            // System.out.println(pq.peek());
            if(pq.peek()>=K) return answer;
            else return -1;    
        }
        else return answer;
    }
    public boolean check(PriorityQueue<Integer> pq,int k){
        boolean rtn = true;
        Iterator it = pq.iterator();
        while(it.hasNext()){
            if((int)it.next()<k) rtn = false;
        }
        return rtn;
    }
}