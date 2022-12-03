import java.util.Random;

public class WeaselProgram {

    public static void main(String[] args) {
        int SIZE = 28, generationCounter = 0, bestPontuation = -1;
        int i, j, points;

        char[] sequence = new char[SIZE];
        char[] helper;
        char[][] copies = new char[100][29];
        char[] listChar = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                'U', 'V', 'W', 'X', 'Y', 'Z', ' ' };

        Random random = new Random();

        char[] textTarget = "METHINKS IT IS LIKE A WEASEL".toCharArray();

        // Generating a random sequence of 28 characters
        for (int count = 0; count < SIZE; count++) {
            int randomNumber = random.nextInt(listChar.length);
            sequence[count] = listChar[randomNumber];
        }

        while (bestPontuation < SIZE) {
            generationCounter++;

            // reproducing one hundred copies
            for (i = 0; i < 100; i++) {
                copies[i] = sequence.clone();
            }

            for (i = 0; i < 100; i++) {
                helper = new char[SIZE];

                for (j = 0; j < SIZE; j++) {
                    if (random.nextFloat() <= 0.05) {
                        int randomNumber = random.nextInt(listChar.length);
                        helper[j] = listChar[randomNumber];
                    } else {
                        helper[j] = copies[i][j];
                    }
                }

                copies[i] = helper;
            }

            for (i = 0; i < 100; i++) {
                points = 0;
                for (j = 0; j < SIZE; j++) {
                    if (copies[i][j] == textTarget[j]) {
                        points++;
                    }

                    if (points > bestPontuation) {
                        bestPontuation = points;
                        sequence = copies[i].clone();
                    }
                }
            }

            System.out.print("Generation  " + generationCounter + " ");
            System.out.println(sequence);
        }
    }
}
