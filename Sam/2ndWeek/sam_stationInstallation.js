function solution(n, stations, w) {
    let answer = 0;
    let point = 0;
    let next = 0;
    stations.push(n+w+1);
    for(let i in stations){
        if(i != 0){
            point = stations[i-1] + w;   
        }
            next = stations[i] - w;
        answer += Math.ceil((next - point - 1) / (2 * w + 1));
    }
    return answer;
}