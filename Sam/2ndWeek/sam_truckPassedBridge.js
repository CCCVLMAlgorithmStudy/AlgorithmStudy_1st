function solution(bridge_length, weight, truck_weights) {
    let time = 0;
    let onBridge = [];
    let bridgeTime = [];
    while(truck_weights.length > 0 || onBridge.length > 0){
        for(let i in bridgeTime) bridgeTime[i]--;
        if(bridgeTime[0] == 0){
            bridgeTime.shift();
            onBridge.shift();
        }
        if(truck_weights[0] + sumTruckOnBridge(onBridge) <= weight){
            onBridge.push(truck_weights.shift());
            bridgeTime.push(bridge_length);
        }
        time++;
    }
    return time;
}
function sumTruckOnBridge(onBridge){
    let sum = 0;
    for(let i in onBridge) sum += onBridge[i];
    return sum;
}