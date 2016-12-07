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
    Point(int max,int buyDay,int sellDay){
        this.max = max;
        this.buyDay = buyDay;
        this.sellDay = sellDay;
    }
        
}
Point brute-force-solution(){
    Point ans(0,0,0);
    for(int i = 0 ; i < DAYS-1 ; i++){
        for(int j =i+1 ; j < DAYS ; j++){
            int temp = price[j]-price[i];
            if(ans.max < temp){
                ans.max = temp;
                ans.buyDay = i;
                ans.sellDay = j;
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
Point divide(){
    init();
    return findMaxSubArray(0,DAYS-1);
}
Point findMaxCrossingSubArray(int low,int mid,int high){
    int leftSum = INT_MIN,maxLeft = mid;
    int sum = 0;
    Point a;
    for(int i = mid ; i >= low ; i--){
        sum += change[i];
        if(sum > leftSum){
            leftSum = sum;
            a.buyDay = i;
        }
    }
    int rightSum = INT_MIN,maxRight = mid;
    sum = 0;
    for(int i = mid+1 ; i < high ; i++){
        sum += change[i];
        if(sum > rightSum){
            rightSum = sum;
            a.sellDay = i;
        }
    }
    a.max = rightSum + leftSum;
    return a;
}
Point findMaxSubArray(int low, int high){
    if(low == high)return new Point(change[low],low,high);
    int mid = (low + high)/2;
    Point leftP = findMaxSubArray(low,mid);
    Point rightP = findMaxSubArray(mid+1,right);
    Point midP = findMaxCrossingSubArray(low,mid,high);
    return leftP.max >= midP.max ? (leftP.max >= rightP.max ? leftP : rightP) : (rightP.max >= midP.max ? rightP : midP);
}

Point findMaxPointUsingDP(){
    int temp[DAYS] ={0}; 
    Point ans(0,0,0);
    for(int i=1;i<DAYS;i++){
        temp[i] += change[i];
        if(temp[i] == 0)temp[i] = 0;
        if(temp[i] > max){
            a.max = temp[i];
            a.sell = i;
        }
    }
    for(int i = sell;i>=0;i--){
        if(temp[i] == 0 ){
            a.buy = i;
            break;
        }
    }
    return ans;
}
