// 11:07
let input = [
    [5,3,7,2,3],
    [3,7,1,6,1],
    [7,2,5,3,4],
    [4,3,6,4,1],
    [8,7,3,5,2],
]

function edge(map) {
    let count = 0;
    for (let i = 0; i < map.length; i++) {
        map[i].push(0);
        map[i].unshift(0);
    }
    let line = Array.from({length:map.length+2},() => 0);
    map.push(line);
    map.unshift(line);

    for (let i = 1; i < map.length-1; i++) {
        for (let j = 1; j < map.length-1; j++) {
            // 현재위치
            // map[i][j]

            // 행 전후, 열 전후
            if (
                map[i][j] > map[i][j-1]
                && map[i][j] > map[i][j+1]
                && map[i][j] > map[i-1][j]
                && map[i][j] > map[i+1][j]
            ) {
                count++
            }
        }
    }
    return count;
}

function solution(arr) {
    let count = 0;
    let dx = [-1, 0, +1, 0];
    let dy = [0, +1, 0, -1];
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            let flag = 1;
            // 하나씩 순회 할 때 상하좌우 스캔
            for (let k = 0; k < 4; k++) {
                let x = i+dx[k];
                let y = j+dy[k];
                if (
                    x >= 0
                    && y >= 0
                    && y < arr.length
                    && x < arr.length
                    && arr[x][y] > arr[i][j]
                ) {
                    flag = 0;
                    break;
                }
            }
            if(flag) count++;
        }
    }
    return count;
}
console.log(solution(input));

// continue: 반복문 유지
// break; 반복문 탈출
// return: 전체 로직 종료