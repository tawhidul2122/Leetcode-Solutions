 int val = INT_MIN;
        int sum ;
        int row = accounts.size(); //row
        int col = accounts[0].size(); //col
        for(int i=0;i<row;i++)
        {
            sum = 0;
            for(int j=0;j<col;j++)
            {
                sum += accounts[i][j];
            }
            val = max(val,sum);
        }
        return val;