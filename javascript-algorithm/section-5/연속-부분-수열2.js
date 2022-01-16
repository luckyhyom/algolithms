let input = [1,2,1,2,3];
// let input = [1,3,5,2,3];
// 1,3일때 카운트가 3개가 되어야함
let expected = 5
let result = 10;

function mySolution(arr, expected) {
    let lt=0, sum=0, count = 0;
    for (let rt = 0; rt < arr.length; rt++) {
        sum+=arr[rt];
        while (sum > expected) {
            sum -= arr[lt++]
        }
        count += (lt-rt+1);
    }


    while (ri < arr.length) {
        if (sum <= m) {
            answer += (ri - li + 1);
            ri++;
            sum += arr[ri];
        } else {
            sum -= arr[li];
            li++;
        }
    }
    
    return result;
}

console.log(mySolution(input, expected));