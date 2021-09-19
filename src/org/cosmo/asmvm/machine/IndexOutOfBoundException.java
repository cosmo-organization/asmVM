/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm.machine;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
class IndexOutOfBoundException extends Exception {
    public IndexOutOfBoundException(String msg){
        super(msg);
    }
}
