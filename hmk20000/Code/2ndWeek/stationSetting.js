function solution(n, stations, w) {
    var answer = 0;
    var start =0;
    var end = 0;
    
    stations.push(n+w+1);
    for(var i in stations){
        //이전 기지국의 범위가 끝나는 다음 위치부터, 현 기지국의 범위가 시작하기 전까지의 길이를 파악
        var station = stations[i];
        
        //시작위치 start
        if(i!=0){
            start = stations[i-1]+w;
        }
        
        //종료위치 end
        end = station-w;
        // end = end>0?end:1;        

        //추가되는 기지국 하나가 커버할 수 있는 길이는 2w+1, 남는 길이에서 2w+1을 나눈 값의 올림값을 추가 기지국 수에 합.
        var tmp = end - start - 1;     
        
        answer+=Math.ceil(tmp/(2*w+1))
        
        // console.log("station : "+station);
        // console.log("start : "+start);
        // console.log("end : "+end);
        // console.log("tmp : "+tmp);
        // console.log("answer : "+answer);
        // console.log();
    }
    return answer;
}