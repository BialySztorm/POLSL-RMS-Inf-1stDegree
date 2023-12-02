class Algorytm {
    public int findMaxIndex(double[] tab) {
        if(tab.length<=0)
            return -1;
        int tmp = 0;
        double tmp1 = tab[0];
        for(int i = 1;  i< tab.length; i++)
        {
            if(tmp1<tab[i])
            {
                tmp = i;
                tmp1 = tab[i];
            }
        }
        return tmp;
    }
}

