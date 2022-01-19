function mySolution(parentheses) {
    let status = 0;

    if ((parentheses.length % 2) !== 0) return 'NO';

    for (const p of parentheses) {
        if (p === '(') status++
        else status--;

        if (status === -1 ) return 'NO';
    }

    if (status !== 0) return 'NO';
    
    return 'YES';
}


function solution(parentheses) {
    let stack = [];
    for (const x of parentheses) {
        if (x === '(') {
            stack.push(x);
        } else {
            if (stack.length === 0) return 'NO';
            stack.pop();
        }
    }

    if (stack.length > 0) return 'NO';

    return 'YES';
}


const input = '(()())()'
console.log(mySolution(input));
console.log(solution(input));

// for(let i=0; i<5; i++) {
//     setTimeout(async () => {
//         console.log(i);
//     }, 1000);
// }

// // 실행된순간 함수는 기억한다. (스냅한다?)
// for(var i=0; i<5; i++) {
//     (function(n){
//         setTimeout(() => {
//             console.log(n);
//         }, 1000);
//     })(i)
// }

// // 함수는 선언된 시점의 값을 기억, 즉시실행의 인자값으로 바가 포문에 돌아갈떄