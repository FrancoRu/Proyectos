import { z } from 'zod'
import { Importance, State } from '../types/types'

export const createprojectSchema = z.object({
  nameproject: z
    .string({
      required_error: 'project is required'
    })
    .min(1),
  description: z.string(),
  deadline: z.string().refine(
    (value) => {
      const parsedDate = new Date(value)
      return !isNaN(parsedDate.getTime()) // Verifica si es una fecha válida
    },
    {
      message: 'Debe ser una cadena de fecha válida'
    }
  ),
  importance: z.nativeEnum(Importance, {
    required_error: 'Importance is required'
  })
})

export const updateprojectSchema = z.object({
  nameproject: z
    .string({
      required_error: 'project is required'
    })
    .min(1)
    .nullable(),
  description: z.string().nullable(),
  deadline: z
    .string()
    .refine(
      (value) => {
        const parsedDate = new Date(value)
        return !isNaN(parsedDate.getTime()) // Verifica si es una fecha válida
      },
      {
        message: 'Debe ser una cadena de fecha válida'
      }
    )
    .nullable(),
  importance: z
    .nativeEnum(Importance, {
      required_error: 'Importance is required'
    })
    .nullable(),
  state: z
    .nativeEnum(State, {
      required_error: 'State is required'
    })
    .nullable()
})
