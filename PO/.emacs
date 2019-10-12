;; Dodawanie plikow do konfiguracji 
(add-to-list 'load-path "~/.emacs_path/")

;; Ustawienia okna
 (if window-system
     (setq default-frame-alist
	   '(
	     (width . 80)
	     (height . 42)
             (background-mode . dark)
	     ;;           (scroll-bar-width . 0)
	     (tool-bar-lines . 0)
	     ;;            (menu-bar-lines . 0)
	     ;;            (scroll-bar-background . "grey75")
	     ;;            (scroll-bar-foreground)
	     (right-fringe . 1)
	     (left-fringe . 0)
	     (screen-gamma)
	     (border-color . "black")
	     (cursor-color . "DarkGoldenrod1")
	     (mouse-color . "DarkOrange")
             (background-color . "black")
             (foreground-color . "LimeGreen")
	     (vertical-scroll-bars)
             (font . "DejaVu Sans Mono-10")
	     (custom-set-variables
	      '(term-default-bg-color "black")    
	      '(term-default-fg-color "LimeGreen")
	      )	     
             )))

(tool-bar-mode -1)
(menu-bar-mode -1)

(when window-system 
  (set-face-foreground 'vertical-border "#499949")
  (set-face-foreground 'mode-line "#499949") ; status bar
  (set-face-background 'mode-line "black")
  (set-face-foreground 'mode-line-inactive "#595959")
  (set-face-background 'mode-line-inactive "black")
  (custom-set-faces
   '(mode-line ((t (:box (:line-width 1 :color "#499949"))))))
  (custom-set-faces
   '(mode-line-inactive ((t (:box (:line-width 1 :color "#499949"))))))
)


(setq current-language-environment "Polish")
(setq ispell-dictionary "polish")

;; Sprawdzanie pisowni w locie
;;(add-hook 'fundamental-mode-hook 'flyspell-mode)
(add-hook 'latex-mode-hook 'flyspell-mode)
(add-hook 'text-mode-hook 'flyspell-mode)
(add-hook          'c-mode-hook 'flyspell-prog-mode)
(add-hook         'sh-mode-hook 'flyspell-prog-mode)
(add-hook        'c++-mode-hook 'flyspell-prog-mode)
(add-hook     'python-mode-hook 'flyspell-prog-mode)
(add-hook   'makefile-mode-hook 'flyspell-prog-mode)
(add-hook 'emacs-lisp-mode-hook 'flyspell-prog-mode)

(add-hook 'text-mode-hook 'auto-fill-mode)

(setq flyspell-issue-welcome-flag nil)

;; Zamiana pytan  yes/no na y/n 
(fset 'yes-or-no-p 'y-or-n-p)

;; Czyszczenie scratch-buffer
;;(setq initial-scratch-message nil)

;;C/C++
;;(require 'cc-mode)
(global-set-key [(f9)] 'compile)
(setq compilation-window-height 8)
(setq compilation-finish-function
      (lambda (buf str)
	
        (if (string-match "exited abnormally" str)
	    
            ;; bledy kompilacji
            (message "compilation errors, press C-x ` to visit")
	  
          ;; brak bledow; komunikat gaszony po  0.5s
          (run-at-time 0.5 nil 'delete-windows-on buf)
          (message "NO COMPILATION ERRORS!"))))

;; kompilacja bez pliku makefile
(add-hook 'c-mode-hook
           (lambda ()
	     (unless (file-exists-p "Makefile")
	       (set (make-local-variable 'compile-command)
                    ;; emulacja zachowania make'a .c.o 
                    ;; $(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<
		    (let ((file (file-name-nondirectory buffer-file-name)))
                      (format "%s -c -o %s.o %s %s %s"
                              (or (getenv "CC") "gcc")
                              (file-name-sans-extension file)
                              (or (getenv "CPPFLAGS") "-DDEBUG=9")
                              (or (getenv "CFLAGS") "-ansi -pedantic -Wall -g")
			      file))))))

;; zwijanie/rozwijanie fragementów kodu
;;   hs-mouse-toggle-hiding             [(shift mouse-2)]
;;   hs-hide-block                      C-c @ C-h
;;   hs-show-block                      C-c @ C-s
;;   hs-hide-all                        C-c @ C-M-h
;;   hs-show-all                        C-c @ C-M-s
;;   hs-hide-level                      C-c @ C-l
;;   hs-toggle-hiding                   C-c @ C-c
(load-library "hideshow")
(add-hook 'c-mode-hook               ; other modes similarly
          '(lambda () (hs-minor-mode 1)))

;; numerowanie kolumn
(column-number-mode 1)
(setq linum-format "%3d ") ;; sprobuj M-x linum-mode

;; szkielet pliku c/h 
;; wywolanie: c-template-file w pliku z rozszerzeniem c lub h
;; makra pomocnicze
(defmacro ins-tag() 
  (insert (concat 
	   "_"(upcase 
	       (file-name-sans-extension 
		(file-name-nondirectory buffer-file-name))
	       )"_H_\n"
		)
	  ))

(defmacro own-c-file()
	(insert "#include <stdio.h>\n\n") 
	(insert "int main(int argc, char* argv[]){\n\n") 
	(insert "   /* Miejsce na umieszczenie kodu */\n\n") 
	(insert "   return 0;\n\n") 
	(insert "}\n")               	
)

;; begin : c-template-file
(defun c-template-file () 
  (interactive)
  (save-restriction
    (save-excursion
      (beginning-of-buffer)
      (when (equal (file-name-extension buffer-file-name) "h")
	(insert "#ifndef  ")
	(ins-tag)
	(insert "#define ")
	(ins-tag)
	(insert "\n\n#endif\n")	
	)
      
      (when (equal (file-name-extension buffer-file-name) "c")
	(own-c-file)
	)
      (end-of-buffer)
      )))
;; end

;; Copy oraz Paste z 'clipboard'
(global-set-key [(shift delete)] 'clipboard-kill-region)
(global-set-key [(control insert)] 'clipboard-kill-ring-save)
(global-set-key [(shift insert)] 'clipboard-yank)

;;uzupelnianie skladnii po nacisnieciu CTRL+TAB
(global-set-key (kbd "C-<tab>") 'dabbrev-expand)

;;skok do zadanej linii
(global-set-key "\C-j" 'goto-line)

(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
;; '(cua-mode t nil (cua-base))
 '(show-paren-mode t))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(mode-line ((t (:box (:line-width 1 :color "#499949")))))
 '(mode-line-inactive ((t (:box (:line-width 1 :color "#499949"))))))

;; niby IDE!
;;(require 'multi-term)
;;(setq multi-term-program "/bin/bash")

;; Wylaczenie ekranu powitalnego
(setq inhibit-splash-screen t)

;;; Local Variables:
;;; mode: lisp        
;;; ispell-local-dictionary: "american"
;;; End:
