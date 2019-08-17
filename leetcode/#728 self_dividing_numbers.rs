struct Solution;

impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        static mut TABLE: [i32; 10000 + 7] = [0; 10000 + 7];
        static mut LEN: usize = 0;

        let table = unsafe { &mut TABLE };
        let len = unsafe { &mut LEN };

        if table[0] == 0 {
            for n in 1..=10000 {
                let mut t = n;
                let is_sdn = loop {
                    let d = t % 10;
                    if d == 0 || n % d != 0 {
                        break false;
                    }
                    t /= 10;
                    if t == 0 {
                        break true;
                    }
                };
                if is_sdn {
                    table[*len] = n;
                    *len += 1;
                    // dbg!((*len,n));
                }
            }
        }

        let find_l = || {
            let mut l: isize = 0;
            let mut r: isize = *len as isize;
            while l < r {
                // dbg!((l,r));
                let mid = (l + r) / 2;
                let t = table[mid as usize];
                if t < left {
                    l = mid + 1;
                } else if t > left {
                    r = mid;
                } else {
                    return mid as usize;
                }
            }
            l as usize
        };

        let find_r = || {
            let mut l: isize = -1;
            let mut r: isize = (*len - 1) as isize;
            while l < r {
                // dbg!((l, r));
                let mid = (l + r + 1) / 2;
                let t = table[mid as usize];
                if t < right {
                    l = mid;
                } else if t > right {
                    r = mid - 1;
                } else {
                    return mid as usize;
                }
            }
            r as usize
        };

        table[find_l()..=find_r()].into()
    }
}

fn main() {
    let ans = Solution::self_dividing_numbers(1, 22);
    println!("{:?}", ans);
}
