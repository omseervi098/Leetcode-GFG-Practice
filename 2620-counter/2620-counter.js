/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        var tmp=n;
        tmp=tmp+1;
        n=tmp;
        return n-1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */