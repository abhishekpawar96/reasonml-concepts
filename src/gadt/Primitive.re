type t' =
 | Int'(int)
 | String'(string)
 | Float'(float)
 | Bool'(bool);

type t('a) = 
 | Int(int): t(int)
 | String(string): t(string)
 | Float(float): t(float)
 | Bool(bool): t(bool);
 /* 
 - We made `t` type polymorphic by specifying `'a`
 - When specify types for data constructors instead of giving `t('a)` to each type we gave them a more concrete type otherwise it would be same as a simple ADT.
 - incase of `Int(int)` we specified its type not as `t('a)` but rather `t(int)`, and similarly for rest of the data constructors. Thus we encoded extra information in our type.
 - The usage `'a` is similar to how we specify for phantom types, in the sense that we specified concrete type for all occurrences of `'a`. 
    GADTs are also sometimes referred as **first class phantom type**. 
 */

let eval: type a.t(a) => a = fun
 | Int(i) => i
 | String(s) => s
 | Float(f) => f
 | Bool(b) => b;

/*

Notice the `type a.` above—we are making `a` a scoped type variable.
In the above code we have `type a.`, read this as 
> for all type a

Thus the whole type signature now reads
> for all type *a*, given a value of type primitive of *a* it returns a value of type *a*.

having `type a .` helps us bring type `a` in scope and thus we can use it for return type.

*/
 