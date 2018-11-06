function solution(bridge_length, weight, truck_weights) {
    let bridge =[];
    let bridge_time =[];
    let answer = 0;
    
    while(bridge.length>0 || truck_weights.length>0){
        
        //move_truck
        for(let i in bridge_time) bridge_time[i]--;
        if(bridge_time[0]==0){
            bridge_time.shift();
            bridge.shift();
        }
        
        if((sum_bridge()+truck_weights[0])<weight+1){
            bridge.push(truck_weights.shift());
            bridge_time.push(bridge_length)
        }
        
        answer++;
        
        // console.log("answer : "+answer)
        // console.log("bridge : "+bridge)
        // console.log("bridge_time : "+bridge_time)
        // console.log("truck_weights : "+truck_weights )
        // console.log("");
        if(answer > 100) break;
    }
    
    return answer;
    function sum_bridge(){
        let rtn=0;
        for(let i in bridge) rtn+=bridge[i];
        return rtn;
    }
}