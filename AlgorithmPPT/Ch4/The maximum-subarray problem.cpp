int DAYS = 17;
int price[DAYS] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90};
int change[DAYS] = {0};
int max =0;
int buyDay=0;
int sellDay=0;
class Point{
    int max = 0;
    int buyDay = 0;
    int sellDay = 0;
}
Point brute-force-solution(){
    Point ans;
    for(int i = 0 ; i < DAYS-1 ; i++){
        for(int j =i+1 ; j < DAYS ; j++){
            int temp = price[j]-price[i];
            if(ans.max < temp){
                ans.max = temp;
                ans.buyDay = i;
                ans.sellDay = i;
            }
        }
    }
    return ans;
}
void init(){
    for(int i=1;i<DAYS;i++){
        change[i] = price[i]-price[i-1];
    }
}
void divide(){
    init();
    
}

