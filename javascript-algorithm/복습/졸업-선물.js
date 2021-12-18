input = [
    [6,6],
    [2,2],
    [4,3],
    [4,5],
    [10,3],
]

function present(list, money) {
    let result = 0;
    list.sort((a,b) => (a[0]+a[1]) - (b[0]+b[1]))
    for (let i = 0; i < list.length; i++) {
        let count = 0;
        let sum = 0;
        for (let j = 0; j < list.length; j++) {
            if (j === i) {
                sum -= list[i][0] / 2;
            }
            let a = list[j][0] + list[j][1];
            sum += a;
            if ( sum <= money ) {
                count++
            } else {
                break;
            }
        }
        result = Math.max(result, count);
    }

    return result;
}

console.log(present(input,28));