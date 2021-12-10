function max(arr) {
    let max = 0;
    let sum = 0;

    for (let i = 0; i < arr.length; i++) {
        sum += arr[i][i]
    }
    if (max < sum) {
        max = sum;
    }
    sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i][(arr.length-1)-i]
    }
    if (max < sum) {
        max = sum;
    }
    sum = 0;

    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            sum += arr[i][j]
        }
        if (max < sum) {
            max = sum;
        }
        sum = 0;
        for (let j = 0; j < arr.length; j++) {
            sum += arr[j][i]
        }
        if (max < sum) {
            max = sum;
        }
        sum = 0;
    }

    return max;
}
function max2(arr) {
    let max = 0;
    let one = 0;
    let two = 0;

    for (let i = 0; i < arr.length; i++) {
        one += arr[i][i];
        two += arr[i][(arr.length-1)-i];
        let row = 0;
        let column = 0;
        for (let j = 0; j < arr.length; j++) {
            row += arr[i][j];
            column += arr[j][i];
        }
        max = Math.max(max, row, column);
    }
    
    return Math.max(max, one, two);
}

console.log(max2([
    [10, 13, 10, 12, 15],
    [12, 39, 30, 23, 11],
    [11, 25, 50, 53, 15],
    [19, 27, 29, 37, 27],
    [19, 13, 30, 13, 19]
]));