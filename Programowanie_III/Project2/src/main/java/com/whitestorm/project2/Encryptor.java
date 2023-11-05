package com.whitestorm.project2;

public class Encryptor {
    private final String[] elements = { "","h","he","li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "nh", "fl", "mc", "lv", "ts", "og" };
    // private final int[] elementsLen = { 0,1,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,2,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };

    private int checkIfExist(String word){
        System.out.print(elements.length);
        for(int i = 1; i < elements.length; i++)
            if(word.equals(elements[i]))
                return i;
        return 0;
    }
    public String Encrypt(String text){
        StringBuilder encrypted = new StringBuilder();
        int[] code = new int[text.length()*4];
        int currIndex = 0, currElement = 1, currCode = 0;

        for (char ch  : text.toCharArray()) {
            if (ch == 'j' || ch == 'q') {
                return "Nie ma możliwości";
            }
        }

        while (currIndex < text.length()) {
            //printf("E%d\n", CurrElement);
            if (elements[currElement].charAt(0) == text.charAt(currIndex)) {
                //printf("I%d\n", CurrIndex);
                currIndex++;
                if (elements[currElement].length() > 1) {
                    if (currIndex != text.length() && elements[currElement].charAt(1) == text.charAt(currIndex)) {
                        code[currCode] = currElement;
                        currCode++;
                        currElement = 1;
                        currIndex++;
                    }
                    else {
                        currElement++;
                        currIndex--;
                    }
                }
                else {
                    code[currCode] = currElement;
                    currCode++;
                    currElement = 1;
                }
            }
            else if (text.charAt(currIndex) == ' ') {
                currIndex++;
                code[currCode] = 0;
                currCode++;
                currElement = 1;
            }
            else {
                currElement++;
            }
            if (currElement >= elements.length) {
                //printf("sizeof\n");
                if (currIndex == 0 || code[currCode - 1] >= elements.length - 1 || code[currCode - 1] == 0) {
                    return "Nie ma możliwości";
                }
                else {
                    currIndex -= elements[code[--currCode]].length();
                    currElement = code[currCode] + 1;
                }
            }
        }

        int tabLen = currCode;
        currIndex = 0;
        for (int i = 0; i < tabLen; i++) {
            //printf("C%d\n", Code[i]);
            if(code[i]>0)
                encrypted.append(Integer.toString(code[i]));
            if (i != tabLen - 1)
                encrypted.append('*');
        }

        return encrypted.toString();
    }
    public String Decrypt(String text){
        StringBuilder decrypted = new StringBuilder();
        String[] encrypted = text.split("\\*");
        for(String element : encrypted)
        {
            try {
                if(element.isEmpty())
                    decrypted.append(" ");
                else if(Integer.parseInt(element) > 0 && Integer.parseInt(element) < 118)
                    decrypted.append(elements[Integer.parseInt(element)]);
                else
                    return "Wrong input!";
            } catch (NumberFormatException e) {
                return "Wrong input!";
            }
        }


        return decrypted.toString();
    }
}