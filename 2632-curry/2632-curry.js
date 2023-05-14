/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        if(args.length>=fn.length){
            return fn(...args)
        }else{
            return function(...nextargs){
                return curried(...args,...nextargs)
            }
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
