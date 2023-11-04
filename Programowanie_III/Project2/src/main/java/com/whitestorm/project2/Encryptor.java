package com.whitestorm.project2;

public class Encryptor {
    private final String[] elements = { "","h","he","li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "nh", "fl", "mc", "lv", "ts", "og" };
    private final int[] elementsLen = { 0,1,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,2,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };

    private int checkIfExist(String word){
        System.out.print(elements.length);
        for(int i = 1; i < elements.length; i++)
            if(word.equals(elements[i]))
                return i;
        return 0;
    }
    public String Encrypt(String text){

        return "";
    }
    public String Decrypt(String text){
        String decrypted = "";
        String[] encrypted = text.split("\\*");
        for(String element : encrypted)
        {
            if(Integer.parseInt(element) > 0 && Integer.parseInt(element) < 118)
            {
                decrypted+=elements[Integer.parseInt(element)];
            }
            else
            {
                return "Wrong input!";
            }
        }


        return decrypted;
    }
}