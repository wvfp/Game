
fn main(){
    let x:[char;5] = ['H','E','L','L','o'];
    let a={
        let c=0;
        c+1
    };
    println!("{}",a);
    let a:bool = fun(x);
    println!("{}",a);

}

fn fun( x:[char;5])->bool{
    let mut i=0;
    while i<5 {
        println!("{}",x[i]);
        i+=1;
    }
    return  true;
}
