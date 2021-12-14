let input = [1,3,5];
let input2 = [2,3,6,7,9];

function concats(arr,arr2) {
    return arr.concat(arr2).sort((a,b)=>a-b);
}
function concats2(arr,arr2) {
    let result = [];
    let n = arr.length;
    let m = arr2.length;
    let p1=p2=0;

    while (p1 < n && p2 < m) {
        if (arr[p1] < arr2[p2]) result.push(arr[p1++]);
        else result.push(arr2[p2++]);
    }
    while (p1 < n) result.push(arr[p1++]);
    while (p2 < m) result.push(arr2[p2++]);
    return result;
}

console.log(concats2(input,input2));