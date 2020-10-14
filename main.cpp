#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Block
{
public:
    Block(string symbol = "  ");
    int block[4][4];
    int row, column;
};

class Matrix
{
public:
    Matrix(int row=0, int column=0);
    int **matrix;
    void printMatrix();
    void insertBlock(Block gameBlock, int scol, int step);
    int trow, tcol;
};

Matrix::Matrix(int row, int column)
{
    trow = row;
    tcol = column;
    matrix = new int*[trow];
    for(int i = 0; i< trow; i++)
    {
        matrix[i] = new int[tcol];
    }
    for(int i=0; i<trow; i++)
    {
        for(int j=0; j<tcol; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Matrix::printMatrix()
{
    for(int i=1;i<trow;i++)
    {
        for(int j=1;j<tcol;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool endgame = false;

int main(int argc, char * argv[])
{
    string symbol;
    int trow, tcol, step, scol;
    ifstream inFile("test1.txt");
    //int count = 2;
    if(inFile.is_open())
    {
        inFile >> trow >> tcol;
        trow += 1;
        tcol += 1;
        Matrix m(trow, tcol);
        //m.printMatrix();
        while(!inFile.eof() && !endgame)
        {
            //count--;
            inFile >> symbol;
            inFile >> scol >> step;
            if(symbol == "End")
                break;
            m.insertBlock(Block(symbol), scol, step);
            //if(count==0) break;
            //Block b(symbol);
        }
        inFile.close();
        m.printMatrix();
    }
    else
    {
        cout << "Cannot open file!" << endl;
    }

}

Block::Block(string symbol)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            block[i][j]=0;
        }
    }
    if (symbol == "T1")
    {
        block[2][0] = 1;
        block[2][1] = 1;
        block[2][2] = 1;
        block[3][1] = 1;
    }
    else if (symbol == "T2")
    {
        block[2][0] = 1;
        block[1][1] = 1;
        block[2][1] = 1;
        block[3][1] = 1;
    }
    else if (symbol == "T3")
    {
        block[2][1] = 1;
        block[3][0] = 1;
        block[3][1] = 1;
        block[3][2] = 1;
    }
    else if (symbol == "T4")
    {
        block[1][0] = 1;
        block[2][0] = 1;
        block[3][0] = 1;
        block[2][1] = 1;
    }
    else if (symbol == "L1")
    {
        block[1][0] = 1;
        block[2][0] = 1;
        block[3][0] = 1;
        block[3][1] = 1;
    }
    else if (symbol == "L2")
    {
        block[2][0] = 1;
        block[2][1] = 1;
        block[2][2] = 1;
        block[3][0] = 1;
    }
    else if (symbol == "L3")
    {
        block[1][0] = 1;
        block[1][1] = 1;
        block[2][1] = 1;
        block[3][1] = 1;
    }

    else if (symbol == "L4")
    {
        block[2][2] = 1;
        block[3][0] = 1;
        block[3][1] = 1;
        block[3][2] = 1;
    }
    else if (symbol == "J1")
    {
        block[3][0] = 1;
        block[1][1] = 1;
        block[2][1] = 1;
        block[3][1] = 1;
    }
    else if (symbol == "J2")
    {
        block[2][0] = 1;
        block[3][0] = 1;
        block[3][1] = 1;
        block[3][2] = 1;
    }
    else if (symbol == "J3")
    {
        block[1][0] = 1;
        block[2][0] = 1;
        block[3][0] = 1;
        block[1][1] = 1;
    }
    else if (symbol == "J4")
    {
        block[2][0] = 1;
        block[2][1] = 1;
        block[2][2] = 1;
        block[3][2] = 1;
    }
    else if (symbol == "S1")
    {
        block[3][0] = 1;
        block[3][1] = 1;
        block[2][1] = 1;
        block[2][2] = 1;
    }
    else if (symbol == "S2")
    {
        block[1][0] = 1;
        block[2][0] = 1;
        block[2][1] = 1;
        block[3][1] = 1;
    }
    else if (symbol == "Z1")
    {
        block[2][0] = 1;
        block[2][1] = 1;
        block[3][1] = 1;
        block[3][2] = 1;
    }
    else if (symbol == "Z2")
    {
        block[2][0] = 1;
        block[3][0] = 1;
        block[1][1] = 1;
        block[2][1] = 1;
    }
    else if (symbol == "I1")
    {
        block[0][0] = 1;
        block[1][0] = 1;
        block[2][0] = 1;
        block[3][0] = 1;
    }
    else if (symbol == "I2")
    {
        block[3][0] = 1;
        block[3][1] = 1;
        block[3][2] = 1;
        block[3][3] = 1;
    }
    else if (symbol == "O")
    {
        block[2][0] = 1;
        block[2][1] = 1;
        block[3][0] = 1;
        block[3][1] = 1;
    }

    if (symbol == "T1" || symbol == "T3" || symbol == "L2" || symbol == "L4" || symbol == "J2" || symbol == "J4" || symbol == "S1" || symbol == "Z1")
    {
        row = 2;
        column = 3;
    }
    else if (symbol == "T2" || symbol == "T4" || symbol == "L1" || symbol == "L3" || symbol == "J1" || symbol == "J3" || symbol == "S2" || symbol == "Z2")
    {
        row = 3;
        column = 2;
    }
    else if (symbol == "I1")
    {
        row = 4;
        column = 1;
    }
    else if (symbol == "I2")
    {
        row = 1;
        column = 4;
    }
    else if (symbol == "O")
    {
        row = 2;
        column = 2;
    }
    /*for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << block[i][j] << " ";
        }
        cout << endl;
    }*/
}

void Matrix::insertBlock(Block gameBlock, int scol, int step)
{
    int currentRow = gameBlock.row; //current是要被放的行
    int refRow = 3;   //blockRow是reference point的那一行
    bool reachBottom = false;
    bool collision = false;
    bool isMoved = false;
    int new_matrix[trow][tcol];
    int pre_matrix[trow][tcol];
    if(step == 0)
    {
        isMoved = true;
    }
    second_drop:;
    for(int i = 0; i < trow; i++) {
        for(int j = 0; j < tcol; j++) {
            new_matrix[i][j] = matrix[i][j];
            pre_matrix[i][j] = matrix[i][j];
        }
    }

    while(!reachBottom && !collision)
    {   //store pre_matrix的值傳到 new_matrix
        for(int i=0; i<trow; i++)
        {
            for(int j=0; j<tcol; j++)
            {
                pre_matrix[i][j] = new_matrix[i][j];
            }
        }
        //dropping from row 1
        for(int i=0; i<gameBlock.row; i++)
        {
            for(int j=0; j<gameBlock.column; j++)
            {
                new_matrix[currentRow-i][scol+j] = matrix[currentRow-i][scol+j] + gameBlock.block[refRow-i][j];
                if(new_matrix[currentRow-i][scol+j] >= 2) // test有沒有block是相撞的
                {
                    collision = true;
                    currentRow -= 1; // move up
                    goto ended;
                }
            }
        }
        currentRow += 1;
        if(currentRow == trow) //check reach bottom row or not
        {
            reachBottom = true; //reach bottom row
            currentRow -= 1;    //move up
        }
        ended:;
    }
    int now = currentRow;
    int now_row = refRow;
    int out = gameBlock.row;
    bool finish = false;
    bool blank = false;
    bool fail = false;

    while(now<=gameBlock.row && collision)
    {
        while(!blank)
        {
        for(int i=0; i<gameBlock.row; i++)
        {
            for(int j=0; j<gameBlock.column; j++)
            {
                if(now-i == 0)
                {
                    blank = true;
                    goto checked;
                }
                if(matrix[now-i][scol+j] + gameBlock.block[now_row-i][j] >=2)
                {
                    now -= 1;
                    goto checked;
                }
            }
        }
        blank = true;
        checked:;
        }
        if(out == 0)
        {
            finish = true;
            break;
        }

       if(now<=0)
        {
            endgame = true;
            break;
        }

        for(int j=0; j< gameBlock.column; j++)
        {
            new_matrix[now][scol+j] = matrix[now][scol+j] + gameBlock.block[now_row][j];
            if(new_matrix[now][scol+j] >= 2)
            {
                now -= 1;
                fail = true;
                break;
            }
        }
        if(!fail)
        {
            if(!isMoved)
            {
                isMoved = true;
                scol += step;
                goto second_drop;
            }
            else{
            int counter = 0;
            for(int j=0; j<gameBlock.column; j++)
            {
                matrix[now][scol+j+step] = new_matrix[now][scol+j];
            }

            //delete
            for(int j=1; j<tcol; j++)
            {
                if(matrix[now][j]==1) counter++ ;
            }
            if(counter == tcol-1)
            {
                for(int i=now; i>1; i--)
                {
                    for(int j=1; j<tcol; j++)
                    {
                        matrix[i][j] = matrix[i-1][j];
                    }
                }
                for(int j=1; j<tcol; j++)
                {
                    matrix[1][j] = 0;
                }
            }
            else
            {
                now -= 1;
            }
            now_row -= 1;
            out -= 1;
        }
        }
    }
    if(!endgame && !finish)
    {
        if(collision)
        {
            for(int i=0; i<gameBlock.row; i++)
            {
                for(int j=0; j<gameBlock.column; j++)
                {
                    matrix[currentRow-i][scol+j+step] = pre_matrix[currentRow-i][scol+j];
                }
            }
        }
        else
        {
            for(int i=0; i<gameBlock.row; i++)
            {
                for(int j=0; j<gameBlock.column; j++)
                {
                    matrix[currentRow-i][scol+j+step] = new_matrix[currentRow-i][scol+j];
                }
            }
        }



        int first_delete = 0;
        int total = 0;
        for(int i=0; i<gameBlock.row; i++)
        {
            int count =0;
            for(int j=1; j<tcol; j++)
            {
                if(matrix[currentRow-i][j]==1)
                {
                    count++;
                }

            }
            if(count == tcol-1)
            {
                for(int j=1; j< tcol; j++)
                {
                    matrix[currentRow-i][j] = -1;
                }
                if(first_delete == 0)
                {
                    first_delete = currentRow-i;
                }
                total += 1;
            }
        }

        if(total!=0)
        {
            for(int i=first_delete; i>=1; i--)
            {
                bool del = false;
                while(matrix[i][1] != -1)   continue;
                for(int j = i-1; j>=1 && !del; j--)
                {
                    if(matrix[j][1] == -1)  continue;
                    for(int k=1; k<tcol; k++)
                    {
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = -1;
                        del = true;
                    }
                }
            }
            for(int i=total; i>=1; i--)
            {
                for(int j=1; j<tcol; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

    }
}


