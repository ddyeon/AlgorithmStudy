
 fun main()
    {
        val date = "20210701"
        val arr : Array<String> = arrayOf("±Ë≈‰Ω∫,20020601")
        
        solution(date, arr)
    }
    
     fun solution(date: String, requests: Array<String>): Int {
        var answer: Int = 0
        var personInfo = arrayListOf<String>()
        
        val start_year = Integer.parseInt(date.substring(0,4))
        val start_birth = Integer.parseInt(date.substring(5))
        
        println(start_year)
        println(start_birth)
        
        for(i in 0 until requests.size)
        {
            var tmpArr = requests[i].split(",") //1π¯¬∞¿Œµ¶Ω∫
            var year :Int = Integer.parseInt(tmpArr[1].substring(0,4))
            var birth  = Integer.parseInt(tmpArr[1].substring(5))
            println(tmpArr[1])
            println(start_year -year)
            
            if(start_year - year >= 20)
                answer++;
            else if(start_year - year == 19)
            {
              if(start_birth > birth)
                answer++;
            }
            else
                continue;
        }
       
        
        
        print(answer)
        return answer
    }