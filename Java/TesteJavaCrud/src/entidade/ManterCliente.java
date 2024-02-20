/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

import controle.Cliente;
import java.sql.PreparedStatement;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import java.sql.ResultSet;

public class ManterCliente extends DAO{
    public void inserir(Cliente a) throws Exception {
    try {
    abrirBanco();
    String query = "INSERT INTO cliente(codigo,nome,email,endereco,telefone) "
            + "values(null,?,?,?,?)";
    pst=(PreparedStatement) con.prepareStatement(query);
    pst.setString(1, a.getNome());
    pst.setString(2,a.getEmail());
    pst.setString(3,a.getEndereco());
    pst.setString(4,a.getTelefone());
    pst.execute();
    fecharBanco();
    } catch (Exception e) {
        System.out.println("Erro " + e.getMessage());
    }
    }
    
    //metodo deletar aluno		
 public void deletarCliente(Cliente a) throws Exception{
	 abrirBanco();
	 String query = "delete from cliente where codigo=?";
	 pst=(PreparedStatement) con.prepareStatement(query);
	 pst.setInt(1, a.getCodigo());
	 pst.execute();
        JOptionPane.showMessageDialog(null, "Cliente deletado com sucesso!");
	fecharBanco();
     }
 
 // metodo listar 
 public ArrayList<Cliente> PesquisarTudo () throws Exception {
       ArrayList<Cliente> alunos = new ArrayList<Cliente>();
         try{
         abrirBanco();  
         String query = "select * FROM cliente";
         pst = (PreparedStatement) con.prepareStatement(query);
         ResultSet tr = pst.executeQuery();
         Cliente a ;
         while (tr.next()){               
           a = new Cliente();
           a.setCodigo(tr.getInt("Codigo"));
           a.setNome(tr.getString("Nome"));
           a.setEmail(tr.getString("Email"));
           a.setEndereco(tr.getString("Endereco"));
           a.setTelefone(tr.getString("Telefone"));
           alunos.add(a);
         } 
         fecharBanco();
       }catch (Exception e){
           System.out.println("Erro " + e.getMessage());
     } 
       return alunos;
     }

 public ArrayList<Cliente> PesquisarTudoDesc () throws Exception {
       ArrayList<Cliente> alunos = new ArrayList<Cliente>();
         try{
         abrirBanco();  
         String query = "select CODIGO, NOME, EMAIL, ENDERECO , TELEFONE FROM cliente ORDER BY CODIGO DESC";
         pst = (PreparedStatement) con.prepareStatement(query);
         ResultSet tr = pst.executeQuery();
         Cliente a ;
         while (tr.next()){               
           a = new Cliente();
           a.setCodigo(tr.getInt("Codigo"));
           a.setNome(tr.getString("Nome"));
           a.setEmail(tr.getString("Email"));
           a.setEndereco(tr.getString("Endereco"));
           a.setTelefone(tr.getString("Telefone"));
           alunos.add(a);
         } 
         fecharBanco();
       }catch (Exception e){
           System.out.println("Erro " + e.getMessage());
     } 
       return alunos;
     }
   public ArrayList<Cliente> pesquisarRegistro(Cliente a) throws Exception {
    ArrayList<Cliente> alunos = new ArrayList<>();
    try {
        abrirBanco();
        String query = "SELECT CODIGO, NOME, EMAIL, ENDERECO, TELEFONE FROM cliente WHERE CODIGO=?";
        pst = con.prepareStatement(query);
        pst.setInt(1, a.getCodigo()); 
        ResultSet tr = pst.executeQuery();

        while (tr.next()) {
            Cliente aluno = new Cliente();
            aluno.setCodigo(tr.getInt("CODIGO"));
            aluno.setNome(tr.getString("NOME"));
            aluno.setEmail(tr.getString("EMAIL"));
            aluno.setEndereco(tr.getString("ENDERECO"));
            aluno.setTelefone(tr.getString("TELEFONE"));
            alunos.add(aluno);
        }
        fecharBanco();
    } catch (Exception e) {
        System.out.println("Erro " + e.getMessage());
    }
    return alunos;
}
 public void editarCliente(Cliente a) throws Exception {
        abrirBanco();
        //JOptionPane.showMessageDialog(null, a.getNome()+ a.getEmail() + a.getIdade());
        String query = "UPDATE cliente set nome = ?, email = ?, endereco = ? , telefone = ? where CODIGO = ?";
        pst = (PreparedStatement) con.prepareStatement(query);
        pst.setString(1, a.getNome());
        pst.setString(2, a.getEmail());
        pst.setString(3, a.getEndereco());
        pst.setString(4, a.getTelefone());
        pst.setInt(5, a.getCodigo());
        pst.executeUpdate();
        JOptionPane.showMessageDialog(null, "Cliente Alterado com sucesso!");
        fecharBanco();
    }
}
