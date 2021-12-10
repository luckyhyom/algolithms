let points = [1,0,1,1,1,0,0,1,1,0]

function cal(points) {
    let reduce = 0;
    let sum = 0;
    for (let i = 0; i < points.length; i++) {
        points[i] > points[i-1]
        if (points[i] === 0) {
            reduce = 0;
            continue;
        }
        reduce++;
        sum += reduce;
    }
    return sum;
}

console.log(cal(points));