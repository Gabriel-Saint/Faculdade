/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

import java.sql.SQLException;

/**
 *
 * @author jes73
 */
public class TesteCon extends DAO{
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        DAO cx  = new DAO();
        cx.abrirBanco();    
    }
}
