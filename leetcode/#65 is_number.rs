// compile: rustc leetcode/#65\ is_number.rs --crate-name leetcode -o a.out --edtion 2018
// fmt: rustfmt leetcode/#65\ is_number.rs
// test: rustc leetcode/#65\ is_number.rs --crate-name leetcode -o a.out --edition 2018 --test && ./a.out  --nocapture

struct Solution;

mod state {
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    #[repr(i8)]
    pub enum Token {
        Blank, // " "
        PM,    // "+"/"-"
        Digit, // "0"~"9"
        Point, // "."
        Exp,   // "e"
        EOF,
    }
    use Token::*;

    impl Token {
        #[inline(always)]
        pub fn from_char(ch: char) -> Result<Self, ()> {
            match ch {
                ' ' => Ok(Blank),
                '+' | '-' => Ok(PM),
                '.' => Ok(Point),
                'e' => Ok(Exp),
                c if c.is_digit(10) => Ok(Digit),
                _ => Err(()),
            }
        }
    }

    pub type State = i8;
    pub type StateTable = [[State; 6]; 12];

    pub const START: State = 0;
    pub const END: State = 11;

    macro_rules! state_table {
        {$($state:expr => [$($token:expr => $target:expr $(, )?)+]$(, )?)+} => {{
            let mut __table: StateTable = [[-1;6];12];
            $(
                let __row = &mut __table[$state as usize];
                $(
                    __row[$token as usize] = $target;
                )+
            )+

            __table
        }};
    }

    pub fn init_table() -> StateTable {
        state_table! {
            START => [Blank => 1, PM => 2, Point => 3, Digit => 4],
            1 => [Blank => 1, PM => 2, Point => 3, Digit => 4],
            2 => [Point => 3, Digit => 4],
            3 => [Digit => 5],
            4 => [Digit => 4, Point => 6, Exp => 7, Blank => 10, EOF => END],
            5 => [Digit => 5, Exp => 7, Blank => 10, EOF => END],
            6 => [Digit => 5, Exp => 7, Blank => 10, EOF => END],
            7 => [PM => 8, Digit => 9],
            8 => [Digit => 9],
            9 => [Digit => 9, Blank => 10, EOF => END],
            10 => [Blank => 10, EOF => END],
        }
    }

    static mut TABLE: Option<StateTable> = None;

    pub fn get_table() -> &'static StateTable {
        unsafe { TABLE.get_or_insert_with(init_table) }
    }
}

impl Solution {
    pub fn is_number_by_array(s: String) -> bool {
        use state::Token;

        let table = state::get_table();

        let mut state = state::START;
        let mut row = unsafe { table.get_unchecked(state as usize) };

        let mut chars = s.chars();

        loop {
            let tk = match chars.next() {
                None => Token::EOF,
                Some(ch) => match Token::from_char(ch) {
                    Err(_) => return false,
                    Ok(tk) => tk,
                },
            };

            match unsafe { row.get_unchecked(tk as usize) } {
                &-1 => {
                    #[cfg(debug_assertions)]
                    eprintln!("{:?} {} => ?", tk, state);
                    return false;
                }
                &target => {
                    #[cfg(debug_assertions)]
                    eprintln!("{:?} {} => {}", tk, state, target);
                    state = target;
                }
            }

            if state == state::END {
                return true;
            } else {
                row = unsafe { table.get_unchecked(state as usize) };
            }
        }
    }

    pub fn is_number(s: String) -> bool {
        Solution::is_number_by_array(s)
    }
}

#[test]
fn test() {
    macro_rules! expect {
        ($s:expr, $ans:expr) => {
            assert_eq!(Solution::is_number($s.to_owned()), $ans);
        };
    }

    expect!("0", true);
    expect!(" 0.1 ", true);
    expect!("abc", false);
    expect!("1 a", false);
    expect!("2e10", true);
    expect!(" -90e3   ", true);
    expect!(" 1e", false);
    expect!("e3", false);
    expect!(" 6e-1", true);
    expect!(" 99e2.5 ", false);
    expect!("53.5e93", true);
    expect!(" --6 ", false);
    expect!("-+3", false);
    expect!("95a54e53", false);
    expect!(".1", true);
    expect!("-.1", true);
    expect!("1.", true);
    expect!("005047e+6", true);
    expect!("46.e3", true);
    expect!(".2e81", true);
    expect!(".", false);
    expect!("+e", false);
    expect!(" .9", true);
}
