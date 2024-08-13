let currentIndex = 0;

function RolarParaDireita() {
    const cards = [cardcomentario1, cardcomentario2, cardcomentario3, cardcomentario4, cardcomentario5, cardcomentario6];
    const setaEsquerda = document.getElementById('setaesquerda');
    const setaDireita = document.getElementById('setadireita');

    // Incrementa o índice para o próximo card
    currentIndex++;

    // Garante que o índice não ultrapasse o limite para exibir sempre 3 cards
    if (currentIndex > cards.length - 3) {
        currentIndex = cards.length - 3;
    }

    // Atualiza a visibilidade dos cards
    cards.forEach((card, index) => {
        if (index >= currentIndex && index < currentIndex + 3) {
            card.style.display = "flex";
        } else {
            card.style.display = "none";
        }
    });

    // Exibe a seta esquerda se não estiver nos primeiros 3 cards
    if (currentIndex > 0) {
        setaEsquerda.style.display = "flex";
    } else {
        setaEsquerda.style.display = "none";
    }

    // Oculta a seta direita se os últimos 3 cards estiverem visíveis
    if (currentIndex >= cards.length - 3) {
        setaDireita.style.display = "none";
    } else {
        setaDireita.style.display = "flex";
    }
}

function RolarParaEsquerda() {
    const cards = [cardcomentario1, cardcomentario2, cardcomentario3, cardcomentario4, cardcomentario5, cardcomentario6];
    const setaEsquerda = document.getElementById('setaesquerda');
    const setaDireita = document.getElementById('setadireita');

    // Decrementa o índice para o card anterior
    currentIndex--;

    // Garante que o índice não seja menor que 0
    if (currentIndex < 0) {
        currentIndex = 0;
    }

    // Atualiza a visibilidade dos cards
    cards.forEach((card, index) => {
        if (index >= currentIndex && index < currentIndex + 3) {
            card.style.display = "flex";
        } else {
            card.style.display = "none";
        }
    });

    // Exibe a seta direita se não estiver nos últimos 3 cards
    if (currentIndex < cards.length - 3) {
        setaDireita.style.display = "flex";
    } else {
        setaDireita.style.display = "none";
    }

    // Oculta a seta esquerda se os primeiros 3 cards estiverem visíveis
    if (currentIndex <= 0) {
        setaEsquerda.style.display = "none";
    } else {
        setaEsquerda.style.display = "flex";
    }
}
