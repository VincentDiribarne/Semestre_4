<%@ page pageEncoding="UTF-8" %>
<style>
    body {
        font-family: 'Roboto', sans-serif!important;
        margin:0;
        padding:0;
        box-sizing: border-box;
    }

    .mainscreen {
        min-height: 100vh;
        width: 100%;
        display: flex;
        flex-direction: column;
        background-color: #DFDBE5;
        background-image: url("https://wallpaperaccess.com/full/3063067.png");
        color: #963E7B;
    }

    .card {
        width: 60rem;
        margin: auto;
        background: white;
        position: center;
        align-self: center;
        top: 50rem;
        border-radius: 1.5rem;
        box-shadow: 4px 3px 20px #3535358c;
        display: flex;
        flex-direction: row;

    }

    .leftside {
        background: #030303;
        width: 25rem;
        display: inline-flex;
        align-items: center;
        justify-content: center;
        border-top-left-radius: 1.5rem;
        border-bottom-left-radius: 1.5rem;
    }

    .product {
        object-fit: cover;
        width: 20em;
        height: 20em;
        border-radius: 100%;
    }

    .rightside {
        background-color: #ffffff;
        width: 35rem;
        border-bottom-right-radius: 1.5rem;
        border-top-right-radius: 1.5rem;
        padding: 1rem 2rem 3rem 3rem;
    }

    p {
        display: block;
        font-size: 1.1rem;
        font-weight: 400;
        margin: .8rem 0;
    }

    .inputbox {
        color: #030303;
        width: 100%;
        padding: 0.5rem;
        border: none;
        border-bottom: 1.5px solid #ccc;
        margin-bottom: 1rem;
        border-radius: 0.3rem;
        font-family: 'Roboto', sans-serif;
        color: #615a5a;
        font-size: 1.1rem;
        font-weight: 500;
        outline: none;
    }

    .expcvv {
        display: flex;
        justify-content: space-between;
        padding-top: 0.6rem;
    }

    .expcvv_text {
        padding-right: 1rem;
    }

    .expcvv_text2 {
        padding: 0 1rem;
    }

    .button {
        background: linear-gradient(
                135deg, #753370 0%, #298096 100%);
        padding: 15px;
        border: none;
        border-radius: 50px;
        color: white;
        font-weight: 400;
        font-size: 1.2rem;
        margin-top: 10px;
        width: 100%;
        letter-spacing: .11rem;
        outline: none;
    }
</style>
<div id="content" class="site-content">
    <div class="mainscreen">
        <div class="card">
            <div class="leftside">
                <img
                        src="https://i.pinimg.com/originals/18/9d/dc/189ddc1221d9c1c779dda4ad37a35fa1.png"
                        class="product"
                        alt="Shoes"
                />
            </div>
            <div class="rightside">
                <form action="./verifCommande.jsp" method="post">
                    <h1>Confirmation</h1>
                    <h2>Information de paiement</h2>
                    <p>Nom du porteur de la carte</p>
                    <input type="text" class="inputbox" name="name" required/>
                    <p>Numero de la carte</p>
                    <input type="number" class="inputbox" name="card_number" id="card_number" required/>

                    <p>Type de la carte</p>
                    <select class="inputbox" name="card_type" id="card_type" required>
                        <option value="">--Selectionner un type--</option>
                        <option value="Visa">Visa</option>
                        <option value="MasterCard">MasterCard</option>
                    </select>
                    <div class="expcvv">

                        <p class="expcvv_text">Date d'expiration</p>
                        <input type="date" class="inputbox" name="exp_date" id="exp_date" required/>

                        <p class="expcvv_text2">CVV</p>
                        <input type="password" class="inputbox" name="cvv" id="cvv" required/>
                    </div>
                    <p></p>
                    <button type="submit" class="button">Envoyer votre argent</button>
                </form>
            </div>
        </div>
    </div>
</div>