package java_implementation;

public class WeaselProgram {
    public static void main(String[] args) {
        Utils utils = new Utils();

        // Criação de uma string inicial aleatoria (28 caracteres)
        utils.setText(utils.gerandoString(utils.getTextGoal(), 1));
        int geracao = 1;
        int melhorPontuacao = 0;

        // Enquanto a melhor pontuação não for atingida
        while (melhorPontuacao != utils.getTextGoal().length()) {
            double variacao = utils.alterandoString();

            System.out.println(
                    "Generation: " + geracao + " " + utils.getCurrentText() + " | Word Score: "
                            + utils.pontuation(utils.getCurrentText()));

            String melhorString = null;

            // fazer 100 copias da string alterada e guardar na lista variável copia
            for (int i = 0; i < 100; i++) {
                String copia = utils.gerandoString(utils.getCurrentText(), variacao);

                // Resultado obtido da comparação entre as strings
                int pontos = utils.pontuation(copia);

                // Melhor sentença é atualizada com base na pontuação obtida
                if (pontos > melhorPontuacao) {
                    melhorString = copia;
                    melhorPontuacao = pontos;
                }
            }

            /*
             * A nova string é atribuída caso a melhor pontuação seja maior qe o resultado
             * das comparações
             */
            if (melhorPontuacao > utils.pontuation(utils.getCurrentText())) {
                utils.setText(melhorString);
            } else {
                utils.setText(utils.getCurrentText());
            }
            geracao++;
        }

        System.out.println(
                "Generation: " + geracao + " " + utils.getCurrentText() + " | Word Score: "
                        + utils.pontuation(utils.getCurrentText()));
    }
}