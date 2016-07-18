// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <list>
#include <vector>
#include <climits>
#include <iostream>

struct RaftPart
{
    int m_empty_seats;
    int m_dwarfs;
    RaftPart(int empty_seats = 0, int dwarfs = 0) : m_empty_seats(empty_seats), m_dwarfs(dwarfs) {};
};

int FindIndex(int N, std::string& coordinate)
{
    int row_part = std::stoi(coordinate);
    int seat_part;
    if (row_part >= 10)
        seat_part = (int)(coordinate[2]) - 64;
    else
        seat_part = (int)(coordinate[1]) - 64;
        
    if( row_part <= N/2 )
        if (seat_part <= N/2)
            return 0;
        else
            return 1;
    else
        if (seat_part <= N/2)
            return 2;
        else
            return 3;  
}

/** @brief function returns the number of dwarfs that may be carried
 * 
 * 
 *  @param N number of raws (and columns) at raft
 *  @param S locations occupied with barrels
 *  @param T locations occupied with dwarfs
 *  @retun maximum dwarfs that maybe taken to the boat
 */
int solution(int N, std::string &S, std::string &T)
{
    std::vector<RaftPart> raft_parts(4, RaftPart((N*N/4), 0));
    
    // remove space occupied with barrels
    size_t start_pos = 0;
    size_t space_pos = 0;
    
    if ( "" != S)
    {
    do
    {
        space_pos = S.find(' ', start_pos);
        std::string coordinate = S.substr(start_pos, space_pos - start_pos);
        int idx = FindIndex(N, coordinate);
        raft_parts[idx].m_empty_seats --;
        start_pos = space_pos + 1;
    }
    while (std::string::npos != space_pos);
    }
    
    if ("" != T)
    {
    start_pos = 0;
    // remove space occupied with dwarfs
    do
    {
        space_pos = T.find(' ', start_pos);
        std::string coordinate = T.substr(start_pos, space_pos - start_pos);
        int idx = FindIndex(N, coordinate);
        raft_parts[idx].m_empty_seats --;
        raft_parts[idx].m_dwarfs ++;
        start_pos = space_pos + 1;
    }
    while (std::string::npos != space_pos);
    }
    
    // find number of dwarfs that may be taken
    int no_of_dwarfs = 0;
    
    // check already present dwarfs and try to balance them
    
    if ((raft_parts[0].m_dwarfs > raft_parts[3].m_dwarfs) && (raft_parts[3].m_empty_seats >= ((raft_parts[0].m_dwarfs - raft_parts[3].m_dwarfs))))
    {
        raft_parts[3].m_empty_seats -= ((raft_parts[0].m_dwarfs - raft_parts[3].m_dwarfs));
        no_of_dwarfs += ((raft_parts[0].m_dwarfs - raft_parts[3].m_dwarfs));
    }
    else if ((raft_parts[0].m_dwarfs < raft_parts[3].m_dwarfs) && (raft_parts[0].m_empty_seats >= ((raft_parts[3].m_dwarfs - raft_parts[0].m_dwarfs))))
    {
        raft_parts[0].m_empty_seats -= ((raft_parts[3].m_dwarfs - raft_parts[0].m_dwarfs));
        no_of_dwarfs += ((raft_parts[3].m_dwarfs - raft_parts[0].m_dwarfs));
    }
    else if (raft_parts[0].m_dwarfs != raft_parts[3].m_dwarfs)
        return -1;
        
        
    if ((raft_parts[1].m_dwarfs > raft_parts[2].m_dwarfs) && (raft_parts[2].m_empty_seats >= ((raft_parts[1].m_dwarfs - raft_parts[2].m_dwarfs))))
    {
        raft_parts[2].m_empty_seats -= ((raft_parts[1].m_dwarfs - raft_parts[2].m_dwarfs));
        no_of_dwarfs += ((raft_parts[1].m_dwarfs - raft_parts[2].m_dwarfs));
    }
    else if ((raft_parts[1].m_dwarfs < raft_parts[2].m_dwarfs) && (raft_parts[1].m_empty_seats >= ((raft_parts[2].m_dwarfs - raft_parts[1].m_dwarfs))))
    {
        raft_parts[1].m_empty_seats -= ((raft_parts[2].m_dwarfs - raft_parts[1].m_dwarfs));
        no_of_dwarfs += ((raft_parts[2].m_dwarfs - raft_parts[1].m_dwarfs));
    }
    else if (raft_parts[1].m_dwarfs !=  raft_parts[2].m_dwarfs)
        return -1;
    
    no_of_dwarfs += ((2 * std::min(raft_parts[0].m_empty_seats, raft_parts[3].m_empty_seats)) + 
                    (2 * std::min(raft_parts[1].m_empty_seats, raft_parts[2].m_empty_seats)));
    return no_of_dwarfs;
}