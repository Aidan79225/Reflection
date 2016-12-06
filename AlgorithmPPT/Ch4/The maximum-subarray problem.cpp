int DAYS = 17;
int price[DAYS] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90};
int max =0;
int buyDay=0;
int sellDay=0;
void brute-force-solution(){
    for(int i = 0 ; i < DAYS-1 ; i++){
        for(int j =i+1 ; j < DAYS ; j++){
            int temp = price[j]-price[i];
            if(max < temp){
                max = temp;
                buyDay = i;
                sellDay = i;
            }
        }
    }
}

