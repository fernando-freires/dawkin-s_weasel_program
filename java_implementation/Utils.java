package java_implementation;

import java.util.Random;

public class Utils {
    static final String textGoal = "METHINKS IT IS LIKE A WEASEL";
    static final char[] listChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ".toCharArray();
    static double probabilidade = 0.05;
    static int SIZE = textGoal.length();
    private static String currentText;
    static Random rand = new Random();

    public String getTextGoal() {
        return textGoal;
    }

    public String getCurrentText() {
        return currentText;
    }

    public void setText(String parent) {
        Utils.currentText = parent;
    }

    /*
     * Diferença entre caracteres da string alvo e a cópia, quanto maior o valor
     * mais próximo está do alvo
     */
    public int pontuation(String copia) {
        int valorComparacao = 0;
        for (int i = 0; i < copia.length(); i++) {
            if (copia.charAt(i) == textGoal.charAt(i))
                valorComparacao++;
        }
        return valorComparacao;
    }

    // Quanto menor o valor mais próximo do objetivo
    public double alterandoString() {
        return (((double) SIZE - pontuation(currentText)) / SIZE * (1 - probabilidade));
    }

    /**
     * Se o valor da variação for menor ou igual a taxa de variação a string de
     * retorno recebe um caracter aleatório, senão recebe o caracter naquele índice
     */

    public String gerandoString(String text, double variacao) {
        String helper = "";
        for (int i = 0; i < text.length(); i++) {
            helper += (rand.nextDouble() <= variacao) ? listChar[rand.nextInt(listChar.length)]
                    : text.charAt(i);
        }
        return helper;
    }
}