package com.whitestorm.project2;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;

public class Controller {
    Encryptor encryptor;

    @FXML
    private TextField textfield;

    public Controller(){
        encryptor = new Encryptor();
    }
    @FXML
    protected void onEncryptButtonClick() {

    }
    @FXML
    protected void onDecryptButtonClick()  {
        textfield.setText(encryptor.Decrypt(textfield.getText()));
    }
    @FXML
    protected void onExitButtonClick() {
        Platform.exit();
    }
}