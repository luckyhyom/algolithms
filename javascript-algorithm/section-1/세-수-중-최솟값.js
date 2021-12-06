// 정렬을 사용하지 않고 세 수중 최솟값 출력

function min (x, y, z) {
    return Math.min(x,y,z);
}
console.log(min(6,5,11));

//Math 사용 외에는?
function min2(x, y, z) {
    let arr = [x, y, z];
    let result = x;
    arr.reduce((pre, cur, i) => {
        if(pre > cur) {
            result = cur;
        } 
    })
    return result;
}
console.log(min2(6,5,11));

// if문만 사용
function min3(x, y, z) {
    let result = x;
    if (x > y) {
        result = y
    }

    if (result > z) {
        result = z
    }

    return result;
}
console.log(min3(6,5,11));