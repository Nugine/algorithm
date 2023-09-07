#![allow(clippy::needless_range_loop)]

use std::collections::{HashMap, HashSet, VecDeque};

type Board = [[u8; 3]; 3];

#[derive(Clone)]
struct State {
    board: Board,
    zero: (usize, usize),
    prev: u32,
    depth: u32,
}

fn print_board(b: &Board) {
    for i in 0..3 {
        for j in 0..3 {
            if b[i][j] != 0 {
                print!("{}", b[i][j]);
            } else {
                print!(" ");
            }
        }
        println!();
    }
    println!();
}

fn main() {
    let init: Board = [[2, 8, 3], [1, 6, 4], [7, 0, 5]];
    let goal: Board = [[1, 2, 3], [8, 0, 4], [7, 6, 5]];

    let mut vis: HashSet<Board> = HashSet::with_capacity(1024);
    let mut states: HashMap<u32, State> = HashMap::with_capacity(1024);
    let mut q: VecDeque<u32> = VecDeque::with_capacity(1024);
    let mut checked_cnt = 0;

    {
        vis.insert(init);
        states.insert(1, State { board: init, zero: (2, 1), prev: 0, depth: 1 });
        q.push_back(1);
    }

    let mut goal_id = 0;
    while let Some(cur_id) = q.pop_front() {
        let cur = states[&cur_id].clone();

        // println!("state {cur_id:>2}: depth = {}, prev = {}", cur.depth, cur.prev);
        // print_board(&cur.board);

        checked_cnt += 1;
        if cur.board == goal {
            goal_id = cur_id;
            break;
        }

        let (zx, zy) = cur.zero;

        // LURD
        for (dx, dy) in [(0, -1), (-1, 0), (0, 1), (1, 0)] {
            let (x, y) = (zx.wrapping_add_signed(dx), zy.wrapping_add_signed(dy));
            if (0..3).contains(&x) && (0..3).contains(&y) {
                let mut next_board = cur.board;
                next_board[zx][zy] = next_board[x][y];
                next_board[x][y] = 0;

                if !vis.contains(&next_board) {
                    vis.insert(next_board);
                    let next_id = vis.len() as u32;
                    let next = State {
                        board: next_board,
                        zero: (x, y),
                        prev: cur_id,
                        depth: cur.depth + 1,
                    };
                    states.insert(next_id, next);
                    q.push_back(next_id);
                }
            }
        }
    }

    let mut trace = vec![goal_id];
    loop {
        let cur_id = *trace.last().unwrap();
        if cur_id == 1 {
            break;
        }
        let cur = &states[&cur_id];
        trace.push(cur.prev);
    }
    trace.reverse();

    // println!("---------------");
    println!("trace:");
    for &cur_id in &trace {
        let cur = &states[&cur_id];
        println!(
            "state {cur_id:>2}: depth = {}, prev = {}",
            cur.depth, cur.prev
        );
        print_board(&cur.board);
    }

    println!("  found states: {}", vis.len());
    println!("checked states: {}", checked_cnt);
}
