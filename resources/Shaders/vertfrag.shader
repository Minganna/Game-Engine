    #ifdef VERTEX                    
    attribute vec3 a_Position;              
    attribute vec2 a_TexCoord; 
    attribute vec3 a_Normal;
                
	                                    
    uniform mat4 u_Model;                  
    uniform mat4 u_Projection;  
    uniform mat4 u_View;               
                                     
    varying vec2 ex_TexCoord;               
    void main()                             
    {                                       
      gl_Position = u_Projection *u_View* u_Model * vec4(a_Position, 1);
      ex_TexCoord = a_TexCoord;      
      if(a_Normal.x==9) gl_Position.x=7;                            
     }                                   
                                            
    #endif              
    #ifdef FRAGMENT                    
                                         
	uniform sampler2D in_Texture;          
	varying vec2 ex_TexCoord;             
	                                   
     void main()                           
      {                                    
      vec4 tex = texture2D(in_Texture,ex_TexCoord);
      gl_FragColor = tex;                
      }                                    
                                          
    #endif                           