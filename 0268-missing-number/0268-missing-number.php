class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        $n=count($nums);
        $summ=($n*($n+1))/2;
        $sum=0;
        for($i=0;$i<$n;$i++)
        {
            $sum+=$nums[$i];
        }
        return $summ-$sum;
    }
}